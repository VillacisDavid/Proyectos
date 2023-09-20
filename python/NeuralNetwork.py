import neurona
class rn_multicapa:
    # Lista que almacena las capas ocultas del perceptron
    hiddenLayers = []
    # Lista que almacena los perceptrones de la capa de salida
    # Las salidas de la RN se encuentran en outputLayer[n].y
    outputLayer = []
    # Valor del sesgo
    vSesgo=1
    
    # inicializa una red neuronal
    # Layers es una lista que especifica los tamaños de las capas que tendra la red neuronal
    # Debe tener al menos 3 elementos.
    # ejemplo: [3,3,1] [3 entradas, 3 capas ocultas, 1 capa de salida]
    def __init__(self,Layers):
        self.hiddenLayers.clear()
        self.outputLayer.clear()        
        if(len(Layers)<3):
            print("Error: Muy pocas dimensiones")
            return
        # Agregamos la entrada del bias1
        Layers[0]+=1  
        # cantidad de capas ocultas de la rn
        n_capasOcultas = len(Layers)-2
        print(n_capasOcultas)
        # Inicializar las capas ocultas, segun lo especificado en Layers
        for idx,layer in enumerate(Layers[1:-1]):
            # almacena una capa temporalmente antes de agregarla a hiddenLayers
            tmp = []
            # crea (layer) neuronas y las enlista
            for n in range(layer):
                tmp.append( neurona(Layers[idx],n_capasOcultas))
            self.hiddenLayers.append(tmp)
         # Inicializar la capa de salida, segun lo especificado en Layers
        for n in range(Layers[-1]):  
            self.outputLayer.append( neurona(Layers[-2]+1,n_capasOcultas)) # agregar 1 entrada para el bias2        
        
    def predict(self, x):
        # Agrega temporalmente la entrada bias al conjunto de entrada
        x.append(self.vSesgo) 
        # Almacena temporalmente las salidas de las neuronas de una capa para pasarlas a la siguiente
        data = []
        # data[0] = capa de entradas
        # data[1:] = salidas de cada capa oculta
        data.append(x.copy())
        # Recorre las capas ocultas para obtener sus salidas
        for inputSet,layer in zip( data, self.hiddenLayers ):
            # almacena temporalmente las salidas las neuronas en la capa
            tmp = []
            # Recorre las neuronas de la capa
            for p in layer:
                p.predict(inputSet)
                tmp.append(p.y)
            # agreda la lista con las salidas de esta capa oculta a la lista data
            data.append(tmp)
        # Con el ultimo elemento de la lista data como entrada
        # calcula el output de las neuronas en la capa de salida
        # Agrega una entrada bias a la ultima capa oculta
        data[-1].append(self.vSesgo)
        for p in self.outputLayer:
            p.predict(data[-1])
            
        x.pop() 
        
    # Recibe un conjunto de entradas x y su conjunto de salidas correctas z
    def train(self, x, z):
        self.predict(x)        
        ## Calculo de deltas
        # Definimos los deltas de las neuronas en la capa de salida
        for p in range( len(self.outputLayer) ):
            self.outputLayer[p].delta = z[p]-self.outputLayer[p].y

        # Definimos los deltas de las neuronas en las capas ocultas
        # Retropropagacion: Comenzamos a calcular los deltas de cada nodo comenzando desde la ultima capa oculta
        allLayers = []
        for l in self.hiddenLayers:
            allLayers.append(l)
        allLayers.append(self.outputLayer)
        
        # Recorre las capas ocultas
        for layer in reversed( range( len(allLayers)-1 ) ):
            # Recorre las neuronas de cada capa
            for p in range( len(allLayers[layer]) ):
                suma = 0
                for np in allLayers[layer+1]:
                    suma += np.delta*np.w[p]
                allLayers[layer][p].delta = suma
        
        ## Calculo de nuevos pesos
        x.append(self.vSesgo)
        temp=[[]]
        # entrenar primera capa
        for p in self.hiddenLayers[0]:
            p.train(x)
            temp[0].append(p.y)
        x.pop()
        # entrenar capas intermedias
        for idx,layer in enumerate(self.hiddenLayers[1:]):
            temp.append([])
            for p in layer:
                p.train(temp[idx])
                temp[idx+1].append(p.y)
        # entrenar capa de salida
        temp[-1].append(self.vSesgo)
        for p in self.outputLayer:
            p.train(temp[-1])
        
        temp.clear()
        allLayers.clear()
        self.predict(x)
        

    def printWeights(self):
        print("--- Neuronas de las capas ocultas ---")
        print(f"<< Capa oculta 1 >>")
        for idx,p in enumerate(self.hiddenLayers[0]):
            print(f"\tNeurona {idx+1}:")
            for i,w in enumerate(p.w[:-1]):
                print(f"\t\tw{i+1} = {w}")
            print(f"\t\tb1 = {p.w[-1]}")
        for idx,layer in enumerate(self.hiddenLayers[1:]):
            print(f"<< Capa oculta {idx+2} >>")
            for p in range( len(layer) ):
                print(f"\tNeurona {p+1}:")
                for w in range(len(layer[p].w)):
                    print(f"\t\tw{w+1} = {layer[p].w[w]}")
        
        print("--- Neuronas de la capa de salida ---")
        for p in range( len(self.outputLayer) ):
            print(f"\tNeurona {p+1}:")
            for w in range(len(self.outputLayer[p].w[:-1])):
                print(f"\t\tw{w+1} = {self.outputLayer[p].w[w]}")
            print(f"\t\tb2 = {self.outputLayer[p].w[-1]}")
            
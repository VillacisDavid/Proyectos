import numpy as np
import math

class neurona:
    # Lista con los pesos para las entradas del perceptron
    w=[]
    # Salida del perceptron
    y=0
    delta=0
    # Funcion de activacion: 1 = funcion sigmoide; 2 = funcion tangente hiperbolica
    f_activ=1
    # Tasa de aprendizaje
    n = 0.8
    
    # Inicializa pesos aleatorios segun la cantidad de entradas que recibira el perceptron
    # por lo general, n_entradas = entradas + bias
    # size_hiddenlayers es la cantidad de capas ocultas de la red neuronal.
    def __init__(self, n_entradas, size_hiddenLayers=1):
        self.w=np.random.rand(n_entradas)*np.sqrt(2/size_hiddenLayers)

    # Funcion de activacion/transferencia
    def factivacion(self, x):
        if(self.f_activ==1):
            # funcion sigmoide
            return 1/(1+math.exp(-x))
        elif(self.f_activ==2):
            # funcion tangente hiperbolica
            return ( 2/(1+math.exp(-2*x)) ) -1
        
    def dfactivacion(self, x):
        if(self.f_activ==1):
            # funcion sigmoide
            return x*(1-x)
        elif(self.f_activ==2):
            # funcion tangente hiperbolica
            return 1-(x*x)

    def predict(self, x):
        suma=0
        for i in range(len(x)):
            suma += x[i]*self.w[i]
            
        self.y = self.factivacion(suma)
    
    def train(self, x):
        for i in range( len(self.w) ):
            self.w[i] += self.n*self.delta*self.dfactivacion(self.y)*x[i]
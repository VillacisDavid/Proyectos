const Dashboard = () => {

    return (
        <div className="flex relative max-w-6xl mx-auto text-textlight">
            <div className="relative w-2/3 mx-1">
                <div className="my-2 py-2 bg-gray-200 rounded-sm">
                    <Sec_Funciones />
                </div>
                <div className="my-2 py-2 bg-gray-200 rounded-sm">
                    <Sec_Reportes />
                </div>
            </div>
            <div className="relative w-1/3 mx-1">
                <div className="my-2 py-2 bg-gray-200 rounded-sm">
                    <Sec_Peliculas />
                </div>
                
            </div>
           
        </div>
              
    );
     
};

const Sec_Funciones = () => (
    <div className="relative">
        <div className="flex items-center h-10 mx-1.5 px-2
        shadow-sm rounded-sm bg-gray-100 font-semibold"> 
            <h1>Funciones programadas </h1>            
        </div>
        <div>
            <div>Esta semana</div>
            <ul>
                <li>Funcion 1</li>
                <li>Funcion 2</li>
                <li>Funcion 3</li>
            </ul>
        </div>
        
    </div>
);
    

const Sec_Reportes = () => (
    <div className="relative">
        <div className="flex items-center h-10 mx-1.5 px-2  
        shadow-sm rounded-sm bg-gray-100 font-semibold">
            <h1>Reporte de Ventas</h1>
        </div>

        <div>
            <div>reporte</div>
        </div>
    </div>
);

const Sec_Peliculas = () => (
    <div className="relative">
        <div className="flex items-center h-10 mx-1.5 px-2  
        shadow-sm rounded-sm bg-gray-100 font-semibold">
            <div className="">Peliculas disponibles</div>
        </div>
            <ul className="flex-row items-center">
                <ul>
                    <li>Pelicula 1</li>
                    <li>Pelicula 2</li>
                    <li>Pelicula 3</li>
                </ul>
            </ul>
    </div>
);

export default Dashboard;
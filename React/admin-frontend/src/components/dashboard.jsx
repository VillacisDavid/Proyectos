import { BiMovie } from "react-icons/bi";

const Dashboard = () => {

    return (
        <div className="dashboard-container">
            <div className="mx-1 my-1">
                <div className="my-1">
                    <Sec_Funciones />
                </div>
                <div className="my-1">
                    <Sec_Reportes />
                </div>
            </div>
            <div className="mr-2 my-2">
                <div>
                    <Sec_Peliculas />
                </div>
                
            </div>
           
        </div>
              
    );
     
};

const Sec_Funciones = () => (
    <div className="section-container">
        <div className="section-title">Funciones programadas</div>
        
    </div>
);
    

const Sec_Reportes = () => (
    <div className="section-container">
        <div className="section-title">Reporte de Ventas</div>
    </div>
);

const Sec_Peliculas = () => (
    <div className="aside-container">
        <div className="section-title">Peliculas disponibles</div>
        <div className="section-content">
            <ul className="flex-row items-center">
                <li><Movie icon={ <BiMovie size="24" /> } title={"Pelicula 1"} status={"Mostrandose"} /></li>
                <li><Movie icon={ <BiMovie size="24" /> } title={"Pelicula 2"} status={"Pre estreno"} /></li>
                <li><Movie icon={ <BiMovie size="24" /> } title={"Pelicula 3"} status={"Proximamente"} /></li>
            </ul>
        </div>
    </div>
);

const Movie = ({ icon, title, status}) => (
    <div className="flex items-center mx-2">
        <div className="flex items-center justify-center h-10 w-10 mx-1 my-1 bg-white">
            {icon}
        </div>
        <div> {title} </div>
        <div className="ml-2"> +{status} </div>
    </div>
        
);

export default Dashboard;

const Dashboard = () => {

    return (
        <div className="absolute">
            <div className="grid grid-cols-5 lg:mx-52 text-green-700">
                <Sec_Funciones />
                <Sec_Reportes />
                <Sec_Peliculas />
            </div>
        </div>
              
    );
     
};

const Sec_Funciones = () => {
    <section className="section-container col-span-3">

    </section>
};

const Sec_Reportes = () => {
    <section className="section-container col-span-3">
        
    </section>
};

const Sec_Peliculas = () => {
    <aside className="aside-container col-span-2">

    </aside>
};

export default Dashboard;
import { BiMenu } from "react-icons/bi";
import { CiUser } from "react-icons/ci";

const Navbar = () => {

    return (
        <div className="navbar-container"> 

            <div className="flex justify-start">
                <NavbarIcon icon={ <BiMenu size="24" /> } id={"sidemenu"} />
                <Title />
                <NavLinks />
            </div>

            <div className="flex justify-end">
                <NavbarIcon icon={ <CiUser size="24" /> } id={"usermenu"} />  
            </div>
                       
        </div>
    );
};

const NavbarIcon = ({ icon }) => ( 
    <div className="navbar-icon">
        <button type="button" onClick={() => mostrarOpciones({id})}>{icon}</button>
    </div>
);

const Title = () => ( 
    <div className='navbar-title'>
        <h1>Cine<span className="text-orange-600">Oasis</span></h1>
    </div>
);

const NavLinks  = () => ( 
    <div className="navbar-links">
        <ul class="flex w-80 justify-evenly">
            <li><a href="/">Dashboard</a></li>
            <li><a href="/">Peliculas</a></li>
            <li><a href="/">Funciones</a></li>
            <li><a href="/">Reportes</a></li>
        </ul>
    </div>
    
    
    
);

export default Navbar;
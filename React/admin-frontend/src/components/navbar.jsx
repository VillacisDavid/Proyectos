import { BiMenu } from "react-icons/bi";
import { CiUser } from "react-icons/ci";
import { Link } from 'react-router-dom';

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
        <Link to="/">Cine<span className="text-orange-600">Oasis</span></Link>
    </div>
);

const NavLinks  = () => ( 
    <div className="navbar-links">
        <ul class="flex w-80 justify-evenly">
            <li><Link to="/peliculas">Peliculas</Link></li>
            <li><Link to="/funciones">Funciones</Link></li>
            <li><Link to="/reportes">Reportes</Link></li>
        </ul>
    </div>
);

export default Navbar;
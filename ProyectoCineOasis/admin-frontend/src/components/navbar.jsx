import { BiMenu } from "react-icons/bi";
import { CiUser } from "react-icons/ci";

const Navbar = () => {
    return (
        <div className="fixed w-screen h-16 flex flex-col  bg-blue-700 "> 
            <div className="grid grid-cols-12 lg:mx-52">
                <NavbarIcon icon={ <BiMenu size="24" /> } id={"sidemenu"} />
                <Title />
                <NavLinks />
                <NavbarIcon icon={ <CiUser size="24" /> } id={"usermenu"} />
            </div>              
        </div>
    );
};

const NavbarIcon = ({ icon }, { id }) => ( <button className="navbar-icon" type="button" onClick={() => mostrarOpciones({id})}>{icon}</button>);

function mostrarOpciones(id){
    
}

const Title = () => ( <h1 className='title-text col-span-5'>Cine<span class="text-orange-600">Oasis</span></h1> );

const NavLinks  = () => ( 
    <div className="invisible sm:visible navbar-links col-span-5">
        <ul className="grid grid-cols-4">
            <li className="navlink-item"><a href="/">Dashboard</a></li>
            <li className="navlink-item"><a href="/">Peliculas</a></li>
            <li className="navlink-item"><a href="/">Funciones</a></li>
            <li className="navlink-item"><a href="/">Reportes</a></li>
        </ul>
    </div>
    
);

export default Navbar;
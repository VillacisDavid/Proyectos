import { BsPlus } from "react-icons/bs";
import { useState } from "react";

const Funciones = () => {

    const NuevaFuncion = () =>{

    };

    return (
        <div className="flex-cols max-w-6xl mx-auto text-textligh py-1 text-textlight">
            
            <div className="flex-cols mx-1">

                <div className="w-full my-1 py-2 px-2
                rounded-sm bg-gray-200">
                    <div className="flex items-center w-full h-10 px-2 
                    shadow-sm rounded-sm bg-gray-100 font-semibold">
                        <h1>Funciones programadas</h1>
                    </div>
                    <div>aaa</div>
                    
                </div>
            
                <div className="flex-cols w-full  my-1 py-2 px-2
                rounded-sm bg-gray-200">
                    <div className="flex items-center w-full h-10 px-2 
                    shadow-sm rounded-sm bg-gray-100 font-semibold">
                        <h1>Funciones pasadas</h1>
                    </div>
                </div>
            </div>
            
            <button className="flex h-12 w-full my-1
            justify-center items-center
            rounded-sm bg-gray-200 hover:bg-gray-100"
            onClick={ NuevaFuncion }>
                <h1>Nueva funcion </h1>
                <BsPlus size="24" />
            </button>    
            

            
        </div>
    );  
};

export default Funciones;
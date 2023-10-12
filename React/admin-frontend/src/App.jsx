import './App.css'
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import Navbar from './components/navbar'
import Dashboard from './components/dashboard'
import Funciones from './components/funciones'
import Peliculas from './components/peliculas'
import Reportes from './components/reportes'

function App() {

  return (
    <Router>
      <div className="flex-col">
        <Navbar /> 
        <Routes>
          <Route exact path='/' element={<Dashboard />}></Route>
          <Route exact path='/peliculas' element={<Peliculas />}></Route>
          <Route exact path='/funciones' element={<Funciones />}></Route>
          <Route exact path='/reportes' element={<Reportes />}></Route>
        </Routes>
      </div>
    </Router>
    
  )
}

export default App

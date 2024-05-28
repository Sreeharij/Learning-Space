import React, {useState} from 'react';

function Car(){
    const [cars,setCars] = useState([]);
    const [carYear,setCarYear] = useState(new Date().getFullYear());
    const [carMake,setCarMake] = useState("");
    const [carModel,setCarModel] = useState("");

    const handleAddCar = () => {
        const newCar = {year: carYear, make: carMake, model: carModel};
        setCars(c => [...c,newCar]);
        setCarYear(new Date().getFullYear());
        setCarMake("");
        setCarModel("");
    }

    const handleRemoveCar = (index) => {
        setCars(c => c.filter((_,i) => index!==i));
    }

    const handleYearChange = (event) => setCarYear(event.target.value);
    const handleMakeChange = (event) => setCarMake(event.target.value);
    const handleModelChange = (event) => setCarModel(event.target.value);

    return(
        <div className='car-container-div'>
            <h2>List of Car Objects</h2>
            <ul>
                {cars.map((car,index) => <li key={index} onClick={() => handleRemoveCar(index)}>{car.year} {car.make} {car.model}</li>)}
            </ul>
            <input type="number" value={carYear} onChange={handleYearChange}></input>
            <input type="text" value={carMake} onChange={handleMakeChange} placeholder='Enter Car Make'></input>
            <input type="text" value={carModel} onChange={handleModelChange} placeholder='Enter Car Model'></input>
            <button onClick={handleAddCar}>Add Car</button>
        </div>
    );
}

export default Car
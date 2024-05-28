import React, {useState} from 'react';

function Car(){
    const [car,setCar] = useState({year: 2024,
                                    make: "Ford",
                                    model: "Mustang"});

    const handleYearChange = (event) => {
        setCar(c => ({...c,year: event.target.value}));
    }

    const handleMakeChange = (event) => {
        setCar(c => ({...c,make: event.target.value}));
    }

    const handleModelChange = (event) => {
        setCar(c => ({...c,model: event.target.value}));
    }

    return(
        <div className='car-div-container'>
            <p>Your Favorite Car is:<br/> <b>{car.year} {car.make} {car.model}</b></p>

            <input type="number" value={car.year} onChange={handleYearChange}></input>
            <input type="text" value={car.make} onChange={handleMakeChange}></input>
            <input type="text" value={car.model} onChange={handleModelChange}></input>
        </div>
    );
}

export default Car
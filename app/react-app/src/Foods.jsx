import React, {useState} from 'react';
function Food(){
    const [foods, setFoods] = useState(['Apple','Orange','Banana']);

    const handleAddFood = () => {
        const newFood = document.getElementById("foodInput").value;
        document.getElementById("foodInput").value = "";
        setFoods([...foods, newFood]);
        
    }

    const handleRemoveFood = (index) => {
        setFoods(foods.filter((_,i) => i!==index));
    }

    return(
        <div className='foods-div-container'>
            <h2>List Of Foods</h2>
            <ol>
            {foods.map((item,index) => <li key={index} onClick={() => handleRemoveFood(index)}>{item}</li>)}
            </ol>
            <input type="text" id="foodInput" placeholder='Enter Food Name'></input>
            <button onClick={handleAddFood}>Add Food</button>
        </div>
    );
}

export default Food
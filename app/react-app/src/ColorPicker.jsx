import React, {useState} from 'react';

function ColorPicker(){
    const [color, setColor] = useState('#FFFFFF');

    const handleColorChange = (event) => {
        setColor(event.target.value);
    }

    return(
        <div className='colour-picker-container'>
            <h1>Color Picker</h1>
            <div className='color-picker-display' style={{backgroundColor: color}}>
                <p>{color}</p>
            </div>
            <label>Select a color: </label>
            <input type="color" value={color} onChange={handleColorChange}></input>
        </div>
    );
}

export default ColorPicker
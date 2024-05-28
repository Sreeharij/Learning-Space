import React, {useState} from 'react';
function LiveInput(){
    const [name,setName] = useState("Guest");
    const [quantity,setQuantity] = useState(1);
    const [comment,setComment] = useState();
    const [payment,setPayment] = useState("None");
    const [shipping,setShipping] = useState();

    const handleNameChange = (event) => {
        setName(event.target.value);
    }

    const handleQuantityChange = (event) =>{
        setQuantity(event.target.value);
    }

    const handleCommentChange = (event) =>{
        setComment(event.target.value);
    }

    const handlePaymentChange = (event) =>{
        setPayment(event.target.value);
    }

    const handleShippingChange = (event) =>{
        setShipping(event.target.value);
    }

    return(
        <div>
            <input value={name} onChange={handleNameChange} placeholder='Enter Name'></input>
            <p>Name: {name}</p>

            <input value={quantity} onChange={handleQuantityChange} type="number"></input>
            <p>Quantity: {quantity}</p>

            <textarea value={comment} onChange={handleCommentChange} placeholder='Enter Instructions'></textarea>
            <p>Delivery Instructions: {comment}</p>
            
            <select value={payment} onChange={handlePaymentChange}>
                
                <option value="cash">Cash</option>
                <option value="Visa">Visa</option>
                <option value="Credit Card">Credit Card</option>
                <option value="Gift Card">Gift Card</option>
            </select>
                <p>Payment: {payment}</p>

            <label>
                <input type="radio" value="Pick Up" checked={shipping==="Pick Up"} onChange={handleShippingChange}></input>
                Pick Up
            </label>
            <br></br>
            <label>
                <input type="radio" value="Delivery" checked={shipping==="Delivery"} onChange={handleShippingChange}></input>
                Delivery
            </label>
            <p>Shipping: {shipping}</p>
        </div>
    );
}

export default LiveInput
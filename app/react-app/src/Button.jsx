function Button(){
    let count = 0;
    const handleClick = (e) => {
        if(e.target.textContent == "Ouch! 😧"){
            e.target.textContent = "Click me 🙂";
        }
        else{
            e.target.textContent = "Ouch! 😧";
        }
    } 
    
    return(
        <button onDoubleClick={(e) => handleClick(e)}>Click me 🙂</button>
    );
}

export default Button
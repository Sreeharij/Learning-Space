function Button(){
    let count = 0;
    const handleClick = (name) => {
        count++;
        if(count > 3){
            console.log(`${name}, Stop Clicking Me`);
        }
        else{
            console.log("That hurts");
        }
    }
    
    return(
        <button onClick={() => handleClick("Bro")}>Click me 🙂  </button>
    );
}

export default Button
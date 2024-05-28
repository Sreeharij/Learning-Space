let imageSrc = "https://imageio.forbes.com/specials-images/imageserve/664a1dbbf613a9beb74f515c/John-Cena/960x0.jpg?format=jpg&width=1440";
let title = "John Cena";
let description = "I wrestle in WWE";
function Card(){
    return(
        <div className="card">
            <img 
            alt="Profile Picture" 
            src={imageSrc} 
            >
            </img>
            <h2>{title}</h2>
            <p>{description}</p>
        </div>
    );       
}

export default Card
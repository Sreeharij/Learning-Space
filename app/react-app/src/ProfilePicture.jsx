function ProfilePicture(){
    const imageUrl = 'https://media.istockphoto.com/id/833852036/photo/money-money-and-money.jpg?s=612x612&w=is&k=20&c=RWqLq0HP4v4OBF0hoCFkoKZK_OiaNM5jmXMPXnL0-BM=';

    const handleClick = (e) => e.target.style.display = "none";

    return(
        <img onClick={(e) => handleClick(e)} src={imageUrl}></img>
    );
}

export default ProfilePicture
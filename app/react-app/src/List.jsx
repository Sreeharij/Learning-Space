import PropTypes from 'prop-types'
function List(props){
    return(
        <div>
        <h3 className="list-category">{props.categories}</h3>
        <ol className="list-items">
            {props.items.map((item,index) => <li key={item.id}>{item.name}: &nbsp;<b>{item.calories}</b></li>)}
        </ol>
        </div>
    );
}
List.defaultProps = {
    categories: "Category",
    items: [],
}
List.propTypes = {
    categories: PropTypes.string,
    items: PropTypes.arrayOf(PropTypes.shape({id: PropTypes.number,
                                                name: PropTypes.string,
                                                calories: PropTypes.number})),
}
export default List
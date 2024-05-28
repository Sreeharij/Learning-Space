import 'bootstrap/dist/css/bootstrap.min.css'
import PropTypes from 'prop-types'

function Student(props){
    const cardStyles = {
        width: '18rem',
        margin: '1rem'
      };

      return (
        <div className="card" style={cardStyles}>
          <div className="card-body">
            <h5 className="card-title">Student Information</h5>
            <h6 className="card-subtitle mb-2 text-muted">Details</h6>
            <p className="card-text"><strong>Name:</strong> {props.name}</p>
            <p className="card-text"><strong>Age:</strong> {props.age}</p>
            <p className="card-text"><strong>Place:</strong> {props.place}</p>
            <p className="card-text"><strong>Student:</strong> {props.is_student ? "Yes" : "No"}</p>
          </div>
        </div>
      );
}
Student.propTypes = {
    name: PropTypes.string,
    age: PropTypes.number,
    place: PropTypes.string,
    is_student: PropTypes.bool,
}
Student.defaultProps = {
    name: "Gues",
    age: 0,
    place: "Unknown",
    is_student: false,
}

export default Student
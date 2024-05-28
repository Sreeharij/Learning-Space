import Card from './Card.jsx'
import Button from './Button.jsx'
import Student from './Student.jsx'
import UserGreeting from './UserGreeting.jsx';
function App(){
  const students_list = [
    { name: 'John Cena', age: 43, place: 'USA', is_student: false },
    { name: 'Jane Doe', age: 21, place: 'UK', is_student: true },
    { name: 'Sam Smith', age: 29, place: 'Canada', is_student: false },
    { name: 'Valentino Rossie', age: 50, place: 'China', is_student: true },
    { name: 'Max Verstappen', age: 212, place: 'Asia', is_student: true },
    { name: 'Adele', age: 29, place: 'Canada', is_student: false },
  ];

  return(
    <div className="container">
      <div className="row">
        {students_list.map((student, index) =>(
          <div key={index} className="col-md-4">
            <Student 
            name={student.name}
            age={student.age}
            place={student.place}
            is_student={student.is_student}>
            </Student>
          </div>

        ))}
      </div>
    </div>
  ); 

  // return(
  //   <>
  //   <UserGreeting isLoggedIn={true} username = "Rody"></UserGreeting>
  //   <UserGreeting isLoggedIn={false} username = "Arjun"></UserGreeting>
  //   </>
  // );
}


export default App

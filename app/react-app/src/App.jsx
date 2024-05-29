import Card from './Card.jsx'
import Button from './Button.jsx'
import Student from './Student.jsx'
import UserGreeting from './UserGreeting.jsx';
import List from './List.jsx'
import ProfilePicture from './ProfilePicture.jsx';
import MyComponent from './MyComponent.jsx';
import Counter from './Counter.jsx'
import LiveInput from './LiveInput.jsx'
import ColorPicker from './ColorPicker.jsx'
import Car from './Car.jsx'
import Foods from './Foods.jsx'
import ToDoList from './ToDoList.jsx'
import WidthHeight from './WidthHeight.jsx'
import DigitalClock from './DigitalClock.jsx'
function App(){
  // const students_list = [
  //   { name: 'John Cena', age: 43, place: 'USA', is_student: false },
  //   { name: 'Jane Doe', age: 21, place: 'UK', is_student: true },
  //   { name: 'Sam Smith', age: 29, place: 'Canada', is_student: false },
  //   { name: 'Valentino Rossie', age: 50, place: 'China', is_student: true },
  //   { name: 'Max Verstappen', age: 212, place: 'Asia', is_student: true },
  //   { name: 'Adele', age: 29, place: 'Canada', is_student: false },
  // ];

  // return(
  //   <div className="container">
  //     <div className="row">
  //       {students_list.map((student, index) =>(
  //         <div key={index} className="col-md-4">
  //           <Student 
  //           name={student.name}
  //           age={student.age}
  //           place={student.place}
  //           is_student={student.is_student}>
  //           </Student>
  //         </div>

  //       ))}
  //     </div>
  //   </div>
  // ); 

  // return(
  //   <>
  //   <UserGreeting isLoggedIn={true} username = "Rody"></UserGreeting>
  //   <UserGreeting isLoggedIn={false} username = "Arjun"></UserGreeting>
  //   </>
  // );

  // const fruits = [{id: 1,name: "apple",calories: 95},
  // {id: 2,name: "orange",calories: 100},
  // {id: 3,name: "banana",calories: 200},
  // {id: 4,name: "coconut",calories: 250},
  // {id: 5,name: "pineapple",calories: 50},
  // ];

  // const vegetables = [{id: 6,name: "tomato",calories: 100},
  // {id: 7,name: "potato",calories: 105},
  // {id: 8,name: "onion",calories: 700},
  // {id: 9,name: "capsicum",calories: 800},
  // {id: 10,name: "chicken",calories: 900},
  // ];

  // return(
  //   <>
  //   {fruits.length > 0 && <List items={fruits} categories="fruits"></List>}
  //   {vegetables.length > 0 && <List items={vegetables} categories="vegetables"></List>}

  //   </>
  // );
  return(
    <>
    <DigitalClock></DigitalClock>
    </>
  );
}


export default App

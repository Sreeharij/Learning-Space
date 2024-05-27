//creating object using object literal
let person = {
    name: "john",
    age: 30,

    print_method: function(){
        return (`The name of this person is ${person.name}`)
    },
    number:{
        mobile: '123',
        landline: '678'
    }
}
console.log(person.print_method());
console.log(person.number.mobile);

//Creating Using Object Contructor
function car(type,brand){
    this.type = type;
    this.brand = brand;
}
let car1 = new car('sedan','toyota');
let car2 = new car('suv','innova');
console.log(car1.brand); 
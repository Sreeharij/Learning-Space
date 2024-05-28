let array = [10,20,30,40,50];

let value = array.some(function(element,index,array){return element > 10});
console.log(value);
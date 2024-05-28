const axiosRequest = require('axios')

axiosRequest   
    .get('https://www.boredapi.com/api/activity')
    .then(response => {
        console.log(`You could ${response.data.activity}`)
    })
    .catch(error => {
        console.error(`Error here: ${error}`)
    })

axiosRequest   
    .get('https://www.boredapi.com/api/activity')
    .then(function(response){
        console.log(`You could ${response.data.activity}`)
    })
    .catch(function(error){
        console.error(`Error here: ${error}`)
    })
console.log("here");

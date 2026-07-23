console.log("Fetching the data of the users using web worker!!");

const worker = new Worker("js/worker.js");
worker.onmessage = function (event){
    const data = event.data;
    if(data.error){
        document.getElementById("users").innerHTML=`<h1 style='color:red'>${data.message}</h1>`;
    }
    else{
        let output=`<table> 
        <tr>
        <th>FirstName</th>
        <th>LastName</th>
        <th>Age</th>
        </tr>
        
        `
        data.users.forEach(user=>{
            output+=`
            <tr>
            <td>${user.firstName}</td>
            <td>${user.lastName}</td>
            <td>${user.age}</td>
            </tr>
            
            `
        })
        output+=`
        </table>
        `
        document.querySelector("#users").innerHTML=output;
        console.log("User data upload successfully!!");
    }
}
worker.postMessage({message:"fetch all the users",url:"https://dummyjson.com/users"});

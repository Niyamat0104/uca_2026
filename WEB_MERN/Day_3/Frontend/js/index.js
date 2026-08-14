 
let userList = []

loadUsers(renderUsers);
renderUsers(userList);

function setUserData(userData,callback){
    userList = userData;
    callback(userList);
}

function loadUsers(callback){
    setTimeout(()=>{
        setUserData(users,callback);

    },2000);
}
function renderUsers(userData){
    if(userData.length === 0){
        document.getElementById("content").innerHTML=`<h3> NO user data found!</h3`;

    }
    else{
        document.getElementById("content").innerHTML=`
         <table border="1">
          ${
            userData.map((item)=>{
                return `<tr>
                    <td>${item.name}</td>
                    <td>${item.age}</td>
                </tr>`
            }).join("")
          }
         </table>
        `
    }
}
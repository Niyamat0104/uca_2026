

const fields = [
    "First Name",
    "Last Name",
    "Email"
]

genrateForm(fields);
function genrateForm(fields){
    document.getElementById("formData").innerHTML=
    ` 
     ${fields.map((field)=>{
        return `
           <label> ${field} : </label>
           <input type = ${field === "Email" ? "email":"text"}><br><br>
        `
     }).join("")}

    `
}
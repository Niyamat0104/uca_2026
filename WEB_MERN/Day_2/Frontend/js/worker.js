self.onmessage = async function(event){
    try{
        const response = await fetch(event.data.url);
        if(!response.ok){
            throw new Error("Error in fetching the user data");

        }
        const data = await response.json();
        if(!data.users || data.users.length == 0){
            self.postMessage({
                error:true,
                message:"No users Found"
            });
            return ;
        }
        else{
            self.postMessage(data);
        
        }


    }
    catch (error){
        self.postMessage({
            error:true,
            message:error.message
        });

    }
};
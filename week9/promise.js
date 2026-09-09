function NewPromise(executorFunction) {

   
    let state = "PENDING";

    
    let value;

   
    let reason;

    
    let fulfilledCallbacks = [];
    let rejectedCallbacks = [];


   

    function resolve(result) {

       
        if (state !== "PENDING") {
            return;
        }

        state = "FULFILLED";
        value = result;

        
        fulfilledCallbacks.forEach(callback => {
            callback();
        });
    }


     

    function reject(error) {

        
        if (state !== "PENDING") {
            return;
        }

        state = "REJECTED";
        reason = error;

       
        rejectedCallbacks.forEach(callback => {
            callback();
        });
    }


   

    function then(onFulfilled, onRejected) {

       
        return new NewPromise((resolveNext, rejectNext) => {


         

            function handleFulfilled() {

                try {

                    
                    if (typeof onFulfilled !== "function") {

                        resolveNext(value);

                        return;
                    }

                   
                    const result = onFulfilled(value);
 
                    resolveNext(result);

                }
                catch (error) {

                   
                    rejectNext(error);
                }
            }


          

            function handleRejected() {

                try {

                   
                    if (typeof onRejected !== "function") {

                        rejectNext(reason);

                        return;
                    }

                  
                    const result = onRejected(reason);

                  
                    resolveNext(result);

                }
                catch (error) {

                    rejectNext(error);
                }
            }


        

            if (state === "FULFILLED") {

                handleFulfilled();

            }
            else if (state === "REJECTED") {

                handleRejected();

            }
            else {

           

                fulfilledCallbacks.push(handleFulfilled);

                rejectedCallbacks.push(handleRejected);
            }

        });
    }

 

    function catchFunction(onRejected) {

        return then(undefined, onRejected);
    }


  
    try {

        executorFunction(resolve, reject);

    }
    catch (error) {

        reject(error);
    }

 

    return {
        then: then,
        catch: catchFunction
    };
}
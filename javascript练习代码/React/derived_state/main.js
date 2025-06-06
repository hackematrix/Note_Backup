function AppContent(){
    const [username,setUsername]=React.useState("");
    const [password,setPassword]=React.useState("");
    const usernameClass=username.length<=5?"input-error":"input";
    const passwordClass=password.length<=5?"input-error":"input";
  

    function handleSubmit(event){
        event.preventDefault();

        if(usernameClass==="input-error"||passwordClass==="input-error")
        {
            return;
        }
        
        console.log("username",username);
        console.log("password",password);

        setUsername("");
        setPassword("");
    }

    return(
        <main 
        >
            <h2>Login Form</h2> 
                

            

            <form onSubmit={handleSubmit} style={{
                textAlign:"center",
            }}>
            <input
            className={usernameClass}
             type="text" 
            value={username}
            onChange={(event)=>
                setUsername(event.target.value)}
             />
            <br/>
            <input 
            className={passwordClass}
            type="password"
            value={password} 
            onChange={(event)=>
                setPassword(event.target.value)} 
            />
            <br/>
            <button 
         
            type="submit" 
            className="btn"
           > Login</button>

            </form>
            
        </main>
    );

}

const appEl=document.querySelector('#app');
const root=ReactDOM.createRoot(appEl);

root.render(<AppContent/>);

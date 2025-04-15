function Input({className,value,onChange}){
    return(
        <input
        className={className}
        type="text"
        value={value}
        onChange={onChange}
      />
    );
}

export default Input;

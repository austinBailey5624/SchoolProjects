 function myFunc()
{
	alert("You called my function");
}
function verify()
{
	var pass1=document.getElementById("password1").value;
	var pass2=document.getElementById("password2").value;
  if(pass1.length<8)
  {
    alert("The password is less than 8 characters long!")
  }
	else if(pass1==pass2)
	{
		alert("The passwords match!");
	}
  else
  {
      alert("the passwords don't match")
  }
}

function prev()
{
	var dragonNum=document.getElementById("mainpic");
	if(dragonNum.name =="image1")
	{
		dragonNum.src="dragon5.jpg";
	  dragonNum.name="image5";
	}
	else if(dragonNum.name == "image2")
	{
		dragonNum.src="dragon1.jpg";
		dragonNum.name="image1";
	}
	else if(dragonNum.name=="image3")
	{
		dragonNum.src="dragon2.jpg";
		dragonNum.name="image2";
	}
	else if(dragonNum.name=="image4")
	{
		dragonNum.src="dragon3.jpg";
		dragonNum.name="image3";
	}
	else if(dragonNum.name=="image5")
	{
		dragonNum.src="dragon4.jpg";
		dragonNum.name="image4";
	}
	else
	{
		alert("ERROR! incorrect address for image")
	}

}

function next()
{
	var dragonNum=document.getElementById("mainpic");
	if(dragonNum.name =="image4")
	{
		dragonNum.src="dragon5.jpg";
	  dragonNum.name="image5";
	}
	else if(dragonNum.name == "image5")
	{
		dragonNum.src="dragon1.jpg";
		dragonNum.name="image1";
	}
	else if(dragonNum.name=="image1")
	{
		dragonNum.src="dragon2.jpg";
		dragonNum.name="image2";
	}
	else if(dragonNum.name=="image2")
	{
		dragonNum.src="dragon3.jpg";
		dragonNum.name="image3";
	}
	else if(dragonNum.name=="image3")
	{
		dragonNum.src="dragon4.jpg";
		dragonNum.name="image4";
	}
	else
	{
		alert("ERROR! incorrect address for image")
	}
}

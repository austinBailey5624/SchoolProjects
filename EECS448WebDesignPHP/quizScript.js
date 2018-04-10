function check()
{
  var q1ans1=document.getElementById("q1a1").checked;
  var q1ans2=document.getElementById("q1a2").checked;
  var q1ans3=document.getElementById("q1a3").checked;
  var q1ans4=document.getElementById("q1a4").checked;

  var q2ans1=document.getElementById("q2a1").checked;
  var q2ans2=document.getElementById("q2a2").checked;
  var q2ans3=document.getElementById("q2a3").checked;
  var q2ans4=document.getElementById("q2a4").checked;

  var q3ans1=document.getElementById("q3a1").checked;
  var q3ans2=document.getElementById("q3a2").checked;
  var q3ans3=document.getElementById("q3a3").checked;
  var q3ans4=document.getElementById("q3a4").checked;

  var q4ans1=document.getElementById("q4a1").checked;
  var q4ans2=document.getElementById("q4a2").checked;
  var q4ans3=document.getElementById("q4a3").checked;
  var q4ans4=document.getElementById("q4a4").checked;

  var q5ans1=document.getElementById("q5a1").checked;
  var q5ans2=document.getElementById("q5a2").checked;
  var q5ans3=document.getElementById("q5a3").checked;
  var q5ans4=document.getElementById("q5a4").checked;


  var intCorrect=0;
  // if(q1ans)
  // {
  //   int1++;
  // //  alert("Detected checkedness for q1");
  // }
  // if(q2ans)
  // {
  //   int1++;
  //   alert("Detected checkednes for q2")
  // }
  document.writeln("Question 1: Which actress plays Rey?");
  document.write("You Answered:");
  if(q1ans1)
  {
    document.writeln("Daisy Ridley");
    intCorrect++;
  }
  else if(q1ans2)
  {
    document.writeln("Carrie Fisher");
  }
  else if(q1ans3)
  {
    document.writeln("Gwendoline Christie");
  }
  else if(q1ans4)
  {
    document.writeln("Christina Chong");
  }
  document.writeln("Correct Answer: Daisy Ridley");
  document.writeln();
  document.writeln();
  document.writeln("Question 2: Who Directed StarWars: The Force Awakens?");
  document.write("You answered:");
  if(q2ans1)
  {
    document.writeln("George Lucas");
  }
  else if(q2ans2)
  {
    document.writeln("JJ Abrams");
    intCorrect++;
  }
  else if(q2ans3)
  {
    document.writeln("Martin Scorsese");
  }
  else if(q2ans4)
  {
    document.writeln("Quinten Tarintio");
  }
  document.writeln("Correct Answer: JJ Abrams");
  document.writeln();
  document.writeln();
  document.writeln("Question 3: Which Sith Lord Established the Rule of Two?");
  document.write("You answered:");
  if(q3ans1)
  {
    document.writeln("Darth Sidious");
  }
  else if(q3ans2)
  {
    document.writeln("Darth Plagueis");
  }
  else if(q3ans3)
  {
    document.writeln("Darth Bane");
    intCorrect++;
  }
  else if(q3ans4)
  {
    document.writeln("Yoda");
  }
  document.writeln("Correct Answer: Darth Bane");
  document.writeln();
  document.writeln();
  document.writeln("Question 4: What is the name of this StormTrooper?");
  document.write("You answered:");
  if(q4ans1)
  {
    document.writeln("FN-2187");
  }
  else if(q4ans2)
  {
    document.writeln("TR-8R");
  }
  else if(q4ans3)
  {
    document.writeln("FN-2199");
  }
  else if(q4ans4)
  {
    document.writeln("Phasma");
    intCorrect++;
  }
  document.writeln("Correct Answer: Phasma");
  document.writeln();
  document.writeln();
  document.writeln("Question 5: Who shot first?");
  document.write("You answered: ");
  if(q5ans1)
  {
    document.writeln("Han Solo");
    intCorrect++;
  }
  else if(q5ans2)
  {
    document.writeln("Greedo");
  }
  else if(q5ans3)
  {
    document.writeln("Tie");
  }
  else if(q5ans4)
  {
    document.writeln("ChewBacca");
  }
  document.writeln("Correct Answer: Han");
  document.write("You Scored: ");
  document.write(intCorrect);
  document.writeln(" out of 5, ");
  intCorrect*=20;
  document.write(intCorrect);
  document.writeln("%");
}

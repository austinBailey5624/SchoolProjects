<?php

function multiply($x, $y)
{
  $z=$x*$y;
  return $z;
}

echo "<table>";
for($i=0; $i<=100;$i++)
{
  echo "<tr>";
  for($j=0; $j<=100; $j++)
  {
    if($j==0 && $i==0)
    {
      echo "<td> </td>";
    }
    else if($j==0)
    {
      echo "<td>" . multiply(1,$i) . "</td>";
    }
    else if($i==0)
    {
      echo "<td>" . multiply(1,$j) . "</td>";
    }
    else
    {
      echo "<td>". multiply($i,$j). "</td>";
    }

  }
  echo "</tr>";
}
echo "</table>";
/*  for($i=0; $i<101; $i++)
  {
    echo "<tr>";
    for($j=0; $j<101; $j++)
    {
      if(i==0&&j==0)
      {
        echo "<td>   </td>";
      }
      else if((i*j)<=9)
      {
        echo "<td>"  . multiply($i, $j) . "  </td>";
      }
      else if((i*j)<=99)
      {
        echo "<td>" . multiply($i, $j) . " </td>";
      }
      else
      {
        echo "<td>100</td>";
      }
    }
    echo "</tr>";
  }
  echo "</table>";
*/
?>

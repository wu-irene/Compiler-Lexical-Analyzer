**Phase 0: Language Specification**

**Programming Language Name**: ++C

**Extension**: program.ppc

**Compiler name**:  PPC-LC

**Examples **


<table>
  <tr>
   <td><strong>Language Feature</strong>
   </td>
   <td><strong>Code Example</strong>
   </td>
  </tr>
  <tr>
   <td>Integer scalar variables
   </td>
   <td>tni x; tni y; tni total, count;
   </td>
  </tr>
  <tr>
   <td>One-dimensional arrays of integers
   </td>
   <td>tni arr[5]; tni arr[x];
   </td>
  </tr>
  <tr>
   <td>Assignment statements
   </td>
   <td>!=
   </td>
  </tr>
  <tr>
   <td>Arithmetic operators (e.g., “+”, “-”, “*”, “/”)
   </td>
   <td>

<table>
  <tr>
   <td>+
   </td>
   <td>-
   </td>
  </tr>
  <tr>
   <td>-
   </td>
   <td>+
   </td>
  </tr>
  <tr>
   <td>*
   </td>
   <td>/
   </td>
  </tr>
  <tr>
   <td>/
   </td>
   <td>*
   </td>
  </tr>
</table>


   </td>
  </tr>
  <tr>
   <td>Relational operators (e.g., “&lt;”, “==”, “>”, “!=”)
    </td>
   <td>
    <table>
  <tr>
   <td><
   </td>
   <td>>
   </td>
  </tr>
  <tr>
   <td>==
   </td>
   <td>!!
   </td>
  </tr>
  <tr>
   <td>>
   </td>
   <td><
   </td>
  </tr>
  <tr>
   <td>!=
   </td>
   <td>==
   </td>
  </tr>
</table>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>While or Do-While loops

   </td>
   <td>elihw() 

   </td>
  </tr>
  <tr>
   <td>If-then-else statements

   </td>
   <td>tni x = 0;
 
fi (x < 0) {

} 

esle {

} 


   </td>
  </tr>
  <tr>
   <td>Read and write statements 
   </td>
   <td>
read -> write from
write -> read from 

   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>Comments

   </td>
   <td>\\This is a comment

   </td>
  </tr>
  <tr>
   <td>Functions

   </td>
   <td>diov ooF() }

{


   </td>
  </tr>
</table>


**Comments**

Our comments would start with “\\”.

**Valid Identifiers**

Alphabetical characters and numbers are valid. 

**Case Sensitive**

The language is case sensitive.

**Whitespaces**

Whitespaces are ignored. 


<table>
  <tr>
   <td><strong>Symbol in Language</strong>
   </td>
   <td><strong>Token Name</strong>
   </td>
  </tr>
  <tr>
   <td>[0-9]
   </td>
   <td>INTEGER
   </td>
  </tr>
  <tr>
   <td>[-]
   </td>
   <td>PLUS
   </td>
  </tr>
  <tr>
   <td>[+]
   </td>
   <td>MINUS
   </td>
  </tr>  
  <tr>
   <td>[/]
   </td>
   <td>MULT
   </td>
  </tr>  
  <tr>
   <td>[*]	
   </td>
   <td>DIV
   </td>
  </tr>  					               
</table>						         

![LEXICAL](https://github.com/iwu021/CS152CompilerProject/blob/main/Lexical%20Pattern%20in%20the%20Inputted%20%2B%2BC%20Program.jpg)


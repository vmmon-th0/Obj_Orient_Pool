
#  Encapsulation

Encapsulation is one of the four fundamental principles of Object-Oriented Programming (OOP). It involves bundling the data (attributes), methods (functions) and classes that operate on the data into a single unit called a class.

Encapsulation in Object-Oriented Programming (OOP) boils down to two main ideas:

**Bundling Data and Methods:** Imagine a blueprint for a house. This blueprint (the class) specifies the rooms (data) and how those rooms are connected and used (methods). Encapsulation groups this information together.

Types of encapsulation in OOPs :
- **Data Member** Encapsulation
- **Method** Encapsulation
- **Class** Encapsulation
 
**Data Protection & Security:** Encapsulating data ensures that it can only be modified in a controlled manner, using specific methods, often called getters and setters. Getters retrieve the value of a data member, and setters update it while potentially performing validations or other logic. This is called _**Controlled Access**_. This reduces the risk of data corruption and makes debugging easier by limiting where data can be corrupted.  To enforce these limits, OOP languages, use access modifiers that specify the type of access permitted at the class and member levels.

The exact modifiers used by an OOP language -- and the rules that govern them -- vary from one language to the next, but most of them support at least the following three modifiers:

1.  **Public.**  The class or member can be accessed within the same class or within any other class in the software program.
2.  **Private.**  The class or member can be accessed only within the class itself. It cannot be accessed by any other classes. Programming languages generally impose restrictions on how the private access modifier can be applied at the class level.
3.  **Protected.**  The class or member can be accessed only within the class itself or within its derived classes. It cannot be accessed by any other classes. Programming languages generally impose restrictions on how the protected access modifier can be applied at the class level.


### Références
- Definition of encapsulation [https://www.techtarget.com/searchnetworking/definition/encapsulation]
- What is Encapsulation in OOPS [https://www.enjoyalgorithms.com/blog/encapsulation-in-oops]
## SOLID PRINCIPLES
A set of object-oriented design principles that aim to help developers write code that is easily extensible, 
maintainable and more reusable.
- Single-Responsibility Principle - 
  Classes should have a single purpose
- Open-Closed Principle - Open for extension but closed for modification
- Liskov Substitution - behavioural clas substitution. If Type A is derived from type B then 
  you should be able to substitute objects of type B for objects of type A
- Interface Segregation - Favor multiple, specific interfaces over single interface
- Dependency Inversion - Depend on abstractions not implementations. high level modules should not depend on low level modules
### Prototype Pattern
Useful when creating very large objects, it cuts down on the
cost of object creation from scratch via efficient cloning.
Why Prototype pattern?
- If you need to clone/copy large objects that require alot of memory and cpu to create
- If you are constantly needing to reconfigure created objects
- For dynamic object creation where the type of object created is selected at runtime
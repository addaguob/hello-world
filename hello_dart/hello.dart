import 'dart:ffi';

void main() {
  print("Hello world");
  print("Hello, Dart!");
  print(3);
  // Singe-line comment

  /*
  Mutli-line
  comment
  */

  // multiply a string for output
  print('3' * 3);

  // variables
  int myInt = 143;
  double myDouble = 41.5;
  print(myInt + myDouble);

  String myName = "Alex";
  print(myName);

  bool isMarried = false;
  isMarried = true;
  print(isMarried);

  dynamic dynAge = 35;
  print(dynAge);
  dynAge = "Thirty-five";
  print(dynAge);

  // number type variable methods
  int iNum = -10;
  print(iNum.isEven);
  print(iNum.abs());

  print(myName.length); // myName = 'Alex'
  print(dynAge.runtimeType); // type

  // String interpolation rather than + operator
  String greeting = "Hello";
  greeting = greeting + ", World!"; // not recommended
  // braces not necessary if var is only string
  greeting = "${greeting} Hello Alex!";
  greeting = "Hi $myName and world!";
  greeting = "$myName has ${myName.length} letters.";
  print(greeting);

  // Use dollar as string
  iNum = 10;
  print("I have \$$iNum. Okay.");

  // Assign multi-line string value
  greeting = """Hi, my name is Alex!
  I am \nlearning
Dart!""";
  print(greeting);

  // var, final, const (type inference system)
  var myVar = 1; // auto identify as int type
  //myVar = "abc"; // not dynamic
  myVar = 2; // but can be reassigned with same type
  print(myVar);

  final myFinDouble = 2.5;
  // myFinDouble = 3.5; // error
  print(myFinDouble);

  const myConst = "abc";
  // myConst = "def"; // error
  print(myConst);

  // final is runtime constant
  final myClock = DateTime.now();
  print(myClock);

  //const is compiletime constant
  //const myClock2 = DateTime.now(); //error

  // Optional variables: String/int/bool and null
  int? myOpInt = null; // int myOpInt = null; // error
  print(myOpInt); // although it's redundant, since null is auto assigned
  myOpInt = 143;
  print(myOpInt);

  String? myStrCents; // null is auto assigned
  print(myStrCents);
  myStrCents = "25 cents";
  print(myStrCents);

  // String myPesos; // Error: Non-null can't be used
  // print(myPesos);

  // null safety
  print(myStrCents.length); // can still print access length method
  myStrCents = null; // now let's see
  print(myStrCents?.length); // prints null as null using '?'
  print(myStrCents?.length ?? 0); // print 0 instead of 'null'
  // print(myStrCents!.length); // '!' means myStrCents can't be null, no compiletime error but there is runtime error
  // myStrCents = myStrCents?.length ?? "Nothing"; // doesn't work

  // Control flow with If statements
  dynAge = 19;
  if (dynAge >= 60) {
    print('Old Adult');
  } else if (dynAge >= 18) {
    print('Adult');
  } else {
    print('Minor');
  }

  // C-like syntax with && and || though non-zero is not true
  // if (dynAge) print('dynAge is non-zero'); // error
  if (dynAge >= 18 && dynAge < 20) {
    print("TeendynAger");
  }

  // String can be compared using ==
  greeting = "Hi!";
  if (greeting == "Hi!") {
    print("Hello");
    greeting = '';
  }

  // if isEmpty, isNotEmpty
  if (greeting.isEmpty) {
    print("Empty greeting");
    greeting = 'Hey there!';
  }

  // Ternary and string startsWith, endsWith
  String reply = greeting.startsWith('H') ? 'Hi there!' : 'What?';
  print(reply);
  print(reply.endsWith('ello!') ? "Alright!" : "Hello!");

  // Switch statement
  greeting = "Yow!";
  dynAge = 20;
  switch (greeting) {
    case "Hello!":
      reply = "Hi!"; // No break statement like in C
    case "Hi!":
      reply = "Hello!";
    // == and 'when' in introduced in Dart 3.0+
    case "Yow!" when dynAge == 20: // when is like && in C
      reply = "Hi, 20-year-old dude!";
    case "Yow!":
      break; // needed if there's no statement to serve as brake
    default: // but break stops before the rest of the cases
      reply = "Er--what?";
  }
  print(reply);

  // Loops
  // For-loop
  for (int i = 0; i < 10; i++) {
    print("Hello, world ${i + 1}");
  }

  // 0 is the start, try with substring
  greeting = "Hello world";
  print(greeting.substring(0, 5));

  for (int i = 0; i < greeting.length; i++) {
    print(greeting[i]);
  }

  // While loop
  myInt = 1;
  while (myInt <= 5) {
    if (myInt == 2 || myInt == 3) {
      myInt++;
      continue;
    }
    print(myInt);
    myInt++;
  }

  // Do-while loop
  greeting = "Hello";
  int i = 0;
  do {
    print(greeting[i]);
    i++;
  } while (i < greeting.length);

  // Functions
  void printName() {
    // void function returns nothing after
    print(myName); // executing its block
  }

  // Positional parameters 'name' and 'greeting'
  greeting = "Hey there";
  String greetName(String name, String greeting) {
    // returns a string
    return "$greeting $name";
  }

  // Positional function types and return types
  (int, String) currentWallet() {
    return (200, "Pesos");
  }

  printName();
  print(greetName("Paul", "Bless you"));
  print(greetName(myName, greeting));
  print(currentWallet().toString());
  // $1 and $ 2 are getters
  print("I have ${currentWallet().$1} ${currentWallet().$2}");

  // Required function parameters
  void printGreeting(
      {required String name, required int age, required String greeting}) {
    // this is because with just 'String name', 'name' will have implicit value of null and it's not 'String?
    // 'required' will assure a non-null value is passed
    print("$name, $age years of age, greets, '$greeting'");
  }

  printGreeting(name: "Kelly", age: 27, greeting: "Congrats!");

  // Positional function arguments first before required args

  void doGreeting(int? age, bool isMarried,
      {required String name, required String greeting}) {
    print("$name, $age years of age, greets, '$greeting'");
  }

  doGreeting(35, false, name: "Lex", greeting: "Kamusta");

  // Function return data type and packed variable
  (int, String) getAgeName() {
    return (12, "Cyprian");
  }

  (int, String) ageName = getAgeName();
  print(ageName);
  print("${ageName.$2} is ${ageName.$1}");

  // Function return types as variable properties
  ({int age, String color}) showAgeColor() {
    return (age: 12, color: "White");
  }

  final ageColor = showAgeColor();
  print(
      "Ian's age is ${ageColor.age} and his fave color is ${ageColor.color}.");

  // Function as argument/parameter
  Function showName() {
    return () {
      print("Show name: Alex");
    };
  }

  final nameAlex = showName();
  nameAlex(); // it prints but also prints the returned null value
  print(() {
    iNum = 101;
    print(iNum);
  }()); // () means to call that anonymous function right away
  () {
    // removed print to see if 'null' is not printed
    iNum = 102;
    print(iNum);
  }();

  // Arrow function like in JavaScript
  String printTheName(int theAge) => "Alexander is $theAge years old.";
  final theName = printTheName(15);
  print(theName);

  // Void arrow function
  void printThree() => print("Three");
  printThree();

  // // Classes, PascalCase in namingClasses
  // Cookie cookie = Cookie();
  // final another_cookie = Cookie(); // another technique
  // cookie.baking();
  // another_cookie.baking();
  // another_cookie.shape = "Rectangle";
  // print("There are ${cookie.shape} and ${another_cookie.shape} shapes.");

  // // Class without objects are re-instantiated
  // print(Cookie().size);
  // Cookie().size = 14.7; // not really changing size
  // print(Cookie().size); // still 15.2

  // Class constructor
  final cookie1 = Cookie('Square', 17);
  // final cookie1 = new Cookie('Square', 17); // new not required
  print("My cookie is ${cookie1.shape} with size of a ${cookie1.size_cm} cm");
  print(cookie1._height); // not really private if in the same file

  // Static variables and functions
  final consVar = Constants();
  // print(consVar.greet); // doesn't work for static
  print(Constants.greet); // static usage without obj instantiation
  print(consVar.bye);
  print(Constants.giveInt());

  // Object Oriented Progrmaming 4 pillars:
  // Inheritance, Abstraction, Polymorphism and Encapsulation

  // OOP Inheritance using 'extends'
  Car car = Car();
  print(car.isEngineWorking);
  print(car.noOfWheels);
  // Vehicle type but Car object / demo: extends, implements
  Vehicle truck = Car();
  print((truck as Car).noOfWheels); // to access that of Car
  // demo @override
  car.accelerate(); // 5 of Supervehicle + 10 of Vehicle
  print(car.speed);

  // OOP Abstraction hides implementation details
  // final bigMachObject = Machine(); // can't be instantiated
  final lilMachObject = lilMachine();
  lilMachObject.engineStart();
  final smallMachObject = smallMachine();
  // OOP Polymorphism allows methods in many forms
  smallMachObject.engineStart();
  // OOP Encapsulation - data protection
  final me = _Person();
  me._getName(); // not really private within the same file

  // Mixin (mixes in properties of another Class)
  final alex = Man();
  alex.eatingFeature();

  // Class Modifiers: sealed class, final class, base class, interface class
  alex.carnivoreStatus(); // Sealed class demo
  final pj = Man(); // mixin: Man extends Animal with Carnivore_feature
  pj.rationalAnimal();
  pj.eatingFeature();
  // Sealed class for sub-types
  Animal cowpet = Cow();
  switch (cowpet) {
    case Man():
      print("human");
      cowpet.eatingFeature();
    case Cow():
      print("cow");
      cowpet.eatingFeature();
  }
  // sealed class can't be instantiated like abstract class
  // final class can be constructed/instantiated
  // final class like sealed class can't be implemented or extended
  // outside its root library unless inside the same library
  // base class can't be implemented but can be extended
  // base class when extended, its constructor gets called
  // interface class is reverse of base class,
  // interface class can be implemented but not extended
  // interface class can be implemented outside the library
  // interface class can be constructed (so called not a proper interface)
  // abstract interface class cannot be constructed, with the addition of abstract keyword, interface class is a true/proper interface that cannot be constructed
  // mixin class <className> can be combined for later mix with 'with' keyword
  // normal non-mixin class can use 'with' before Dart 3.0, but now, only mixin <className> can be extended using 'with'
  // end of OOP

  // Lists
  List list = [10, "twenty", false]; // dynamic list
  print(list);
  print(list.runtimeType);
  print(list[0]); // print one element from list like array in C
  print(myName[0]); // same with String element
  List<int> grades = [80, 85, 90]; // <int> is called generics
  print(grades);
  // more on generics, see: Class with generics
  final student = Student<String>('Alex Thunder');
  print(student.name);
  // to use dynamic generics, use <T>
  final pupil = Pupil('Lex Thunder');
  // it's like Pupil<String>('Lex Thunder');
  print(pupil.name);
  print("This is ${pupil.toString()}");
  // List of objects vs list of dynamic elements:
  // List of class Objects are non-nullable, everything is object except null
  List<Object> iLy = [143, "I love you", true];
  iLy.insert(2, [2, 4, 6]);
  print(iLy);
  final removedObj = iLy.removeAt(0);
  print("$iLy ejects $removedObj");
  print(iLy.contains(true) ? "It has trueness." : "There's falseness");
  print(iLy.join('...'));

  // Set is like List but without duplicates
  Set<Object> mySet = [1, 1, '4', 3.0, 3, false].toSet();
  mySet.forEach((element) => print("$element is ${element.runtimeType}"));

  // Map is like Python's dictionary with <key, value> pairs
  Map<String, double> studentGrades = {"Ale": 85.5, "Lex": 87.25, "Xel": 90.75};
  print(studentGrades);
  // Map keys and values display using for-loop
  for (int i = 0; i < studentGrades.length; i++) {
    print(
        "${studentGrades.keys.toList()[i]} = ${studentGrades.values.toList()[i]}");
  }
  // Map keys and values display using forEach method
  studentGrades.forEach((key, value) => print("$key has a grade of $value"));

  // List of Maps
  List<Map<String, double>> students = [
    {
      "English": 85.25,
      "Filipino": 82.50,
    },
    {
      "English": 88.25,
      "Filipino": 87.50,
    },
    {
      "English": 83.25,
      "Filipino": 84.50,
    },
  ];
  students.map((e) => print(e)).toList();
  students
      .map((e) => e.forEach((k, v) => print("key $k has value of $v")))
      .toList();

  // Enums
  final student1 = EnrollStudent("Ven", Course.BSIT);
  final student2 = EnrollStudent("Richard", Course.BSCS);
  student1.showCourse();
  student2.showCourse();

  // Exception Handling
  print(10 ~/ 3);
  print(10 / 0);
  try {
    print(10 ~/ 0);
  } catch (error) {
    print(error);
  } finally {
    print("Just proceed to printing the name:");
  }
  print("SWE Alex");
} // endmain
//
// currently at 05 55 00 in youtube.com/watch?v=CzRQ9mnmh44
//

enum Course {
  // can also implement a Class
  BSCS(24000),
  BSCoE(27000),
  BSIT(21000);

  final int tuition_php;
  const Course(this.tuition_php);
}

class EnrollStudent {
  final String name;
  final Course course;

  EnrollStudent(this.name, this.course);

  void showCourse() {
    print("${course.name} costs P${course.tuition_php}");
  }
}
// ----------Classes demo and exploration----------

// Class with generics demo
class Student<String> {
  final String name;
  Student(this.name);
}

class Pupil<T> {
  // T can infer int, double, String, bool
  final T name; // rather than 'dynamic' keyword
  Pupil(this.name);
  void setName(T name) {
    print('New name: $name');
  }
}

// Mixin demo: man is carnivore and some irrational animal
mixin Carnivore_Feature {
  bool isCarnivore = true;
}

// Sealed class cannot be instantiated.
// Also can't be inherited/implemented outside it's file
sealed class Animal with Carnivore_Feature {
  void eatingFeature() =>
      isCarnivore ? print("Can eat meat") : print("Vegitarian");
}

class Man extends Animal {
  void carnivoreStatus() => print("Is it carnivore? $isCarnivore");
  void rationalAnimal() => print("Man is a rational animal.");
}

class Cow implements Animal {
  @override
  bool isCarnivore = false;

  @override
  void eatingFeature() {
    isCarnivore ? print("Rarely ears meat") : print("Not a carnivore");
    print("Eats grass or plants.");
  }
}

// For Encapsulation notes
class _Person {
  String _name = 'Alex'; // underscore signifies private data
  void _getName() {
    print(_name);
  }
}

// Abtract allows function call with no block
abstract class Machine {
  int cores = 2;
  void engineStart();
}

// Unlike 'extends', 'implements' forces override on all methods/properties
class smallMachine implements Machine {
  @override
  int cores = 4;

  @override
  void engineStart() {
    print("New version of engine starting...");
  }
}

// Fill in what abstract Class needs
class lilMachine extends Machine {
  @override
  void engineStart() {
    print("Starting engine with ${cores} cores...");
  }
}

// Grandfather class so to speak
class Supervehicle {
  int speed = 15;
  void accelerate() {
    speed += 30;
  }
}

// Inheritance Demo
class Vehicle extends Supervehicle {
  // Parent class / Super class
  bool isEngineWorking = false;

  @override
  void accelerate() {
    // can be different type but same name
    speed += 15;
  }
}

// can't inherit multiple Superclasses
class Car extends Vehicle implements Supervehicle {
  // Implements speed of Supervehicle
  @override
  int speed = 5; // means re-define the speed
  // Child class / sub class
  int noOfWheels = 4;
  void printSpecs() {
    print(noOfWheels);
  }
}

// Classes, PascalCase in namingClasses
class Cookie {
  // poperties = variables of a class
  String shape; // can be not optional (String?)
  double size_cm; // because there is constructor

  // Constructor
  Cookie(this.shape, this.size_cm) {
    print(this);
    print('Cookie constructor called');
    baking();
  }

  int _height = 0; // private variable is private to a file
  // so separate Class to another file

  // Getter
  int get height => _height;

  //Setter
  set setHeight(int h) {
    // convention: set<PropertyName>
    _height = h;
  }

  // methods = functions of a class
  void baking() {
    print("Baking has started...");
  }

  bool isCooling() {
    return false;
  }
}

// Demo for Static variables
class Constants {
  Constants() {
    // not called with Constants.greet from main()
    print("Constants constructor called...");
  }
  // Static is good for not allocating more memories with obj creation
  // but just for accessing some helpful methods and properties
  static String greet = 'Hello, how are you?';
  String bye = 'Bye!';

  static int giveInt() {
    return 10;
  }
}

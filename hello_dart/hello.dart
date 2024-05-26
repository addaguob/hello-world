void main() {
  print("Hello world");
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
    case "Yow!" when dynAge == 20: // when is like && in C
      reply = "Hi, 20-year-old dude!";
    case "Yow!":
      break; // needed if there's no statement to serve as brake
    default: // but break stops before the rest of the cases
      reply = "Er--what?";
  }
  print(reply);
  // 1h34m04
}

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
  int n1 = 143;
  double n2 = 41.5;
  print(n1 + n2);

  String fname = "Alex";
  print(fname);

  bool isMarried = false;
  isMarried = true;
  print(isMarried);

  dynamic age = 35;
  print(age);
  age = "Thirty-five";
  print(age);

  // number type variable methods
  int num = -10;
  print(num.isEven);
  print(num.abs());

  print(fname.length); // fname = 'Alex'
  print(age.runtimeType); // type

  // String interpolation rather than + operator
  String greeting = "Hello";
  greeting = greeting + ", World!"; // not recommended
  // braces not necessary if var is only string
  greeting = "${greeting} Hello Alex!";
  greeting = "Hi $fname and world!";
  greeting = "$fname has ${fname.length} letters.";
  print(greeting);

  // Use dollar as string
  num = 10;
  print("I have \$$num. Okay.");

  // Assign multi-line string value
  greeting = """Hi, my name is Alex!
  I am \nlearning
Dart!""";
  print(greeting);
}

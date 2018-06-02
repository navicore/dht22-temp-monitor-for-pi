package onextent.iot.dht22

object Main {

  // --- Main method to test our native library
  def main(args: Array[String]): Unit = {
    val dht22 = new Dht22
    val square = dht22.intMethod(5)
    val bool = dht22.booleanMethod(true)
    val text = dht22.stringMethod("java")
    val sum = dht22.intArrayMethod(Array(1, 1, 2, 3, 5, 8, 13))

    println(s"intMethod: $square")
    println(s"booleanMethod: $bool")
    println(s"stringMethod: $text")
    println(s"intArrayMethod: $sum")
  }
}


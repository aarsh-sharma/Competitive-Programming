fun main() {
	var a = readLine()!!.toInt()
	for (i in 1..a){
		var (b,c) = readLine()!!.split(" ").map { it.toInt() }
		if (b < c)
			c = b.also {b = c}
		var x = b-c+1
		var y = 1
		var z = c-1
		println("$x $y $z")
	}
}
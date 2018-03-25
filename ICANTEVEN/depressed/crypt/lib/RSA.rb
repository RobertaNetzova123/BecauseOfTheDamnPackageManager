class RSA
   def initialize n, e, d
     #initializes this instance of RSA with a n,e and d variables of type int. 'n','e' are the public key and 'd' is the private one. This n,e,d should be used when encrypting and decrypting the message

	@n = n
	@e = e
	@d = d
   end
   
   def n
      #returns the value of 'n' passed in the initialize
	return @n
   end
   
   def e
      #returns the value of 'e' passed in the initialize
	return @e
   end
   
   def d
      #returns the value of 'd' passed in the initialize
	return @d
   end
   
   def new_key
      #generates a new 'n','e' and 'd' values following the RSA algorithm. Returns a new array of three elements where the first element is 'n', the second is 'e' and the third is 'd'. Each time it is called a new key must be returned.

	p = Prime.first 500 #generate prime numbers between 0 and 500
	q = Prime.first 500
	p = p.at(rand(1...500))

	n = p * q

	lcm = (p - 1).lcm(q - 1) #return the least commonmultiple(always positive)
	e = rand(lcm)
	while e.gcd(lcm) != 1 #gcd return the the greatest commont divisor
		e = rand(lcm)
	end
	
	d = 0
	while ((d * e)%lcm != 1)
		d = d + 1
	end

	[n,e,d]
	
   end
   
   def encrypt message
      #encrypts the message passed. The message is of type string. Encrypts each symbol of this string by using its ASCII number representation and returns the encrypted message.

	message.chars.map {|ch| ch.ord ** @e % @n}.join(":") 
   end
   
   def decrypt message
      #decrypts the message passed. The message is of type string. Decrypts each symbol of this string Encrypts each symbol of this string by using its ASCII number representationand returns the decrypted message. 
	message.split(":").map {|ch| (ch.to_i ** @d % @n).chr}.join("")
	
   end 
end

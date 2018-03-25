require_relative '../lib/RSA.rb'

RSpec.describe RSA do
	msg = "I dont know what I am doing anymore"
	second_msg = "Hello"
	rsa = RSA.new(1873, 3023, 2753)
	it "#n" do
		expect(rsa.n).to eq 1873
	end

	it "#e" do
		expect(rsa.e).to eq 3023
	end

	it "#d" do
		expect(rsa.d).to eq 2753
	end

	#----------------------------------------
	test = RSA.new(4877, 131, 648)
	
	it "encrypt/decrypt - hardcode for long sentence" do
		expect(test.decrypt(test.encrypt(msg))).to eq(msg)
	end

	it "crypt/decrypt - hardcode" do
		expect(test.decrypt(test.encrypt(second_msg))).to eq(second_msg)
	end

	it "array new_key" do
		expect(rsa.new_key.kind_of?(Array)).to eq true
	end

	it "lenght of the new_key" do
		expect(rsa.new_key.length).to eq 3
	end

	it "crypt/decrypt - new_key" do
		new_keys = test.new_key
		second_rsa = RSA.new new_keys[0],new_keys[1],new_keys[2]
		expect(second_rsa.decrypt(second_rsa.encrypt(msg))).to eq(msg)
	end
end

require_relative '../lib/RomeConverter.rb'

describe RomeConverter do

	rome_converter = RomeConverter.new()
	#test cases
	
	it "Convert 1 to rome" do
		expect(rome_converter.to_rome(1)).to eq "I"	
	end

	it "Convert 4 to rome" do
		expect(rome_converter.to_rome(4)).to eq "IV"	
	end

	it "Convert 5 to rome" do
		expect(rome_converter.to_rome(5)).to eq "V"	
	end
		
	it "Convert 6 to rome" do
		expect(rome_converter.to_rome(6)).to eq "VI"	
	end

	it "Convert 9 to rome" do
		expect(rome_converter.to_rome(9)).to eq "IX"	
	end

	it "Convert 10 to rome" do
		expect(rome_converter.to_rome(10)).to eq "X"	
	end

	it "Convert 11 to rome" do
		expect(rome_converter.to_rome(11)).to eq "XI"	
	end

	it "Convert 19 to rome" do
		expect(rome_converter.to_rome(19)).to eq "XIX"	
	end

	it "Convert 20 to rome" do
		expect(rome_converter.to_rome(20)).to eq "XX"	
	end
	
	it "Convert 49 to rome" do
		expect(rome_converter.to_rome(46)).to eq "XLVI"	
	end

	it "Convert 99 to rome" do
		expect(rome_converter.to_rome(99)).to eq "XCIX"	
	end
	
	it "Convert 51 to rome" do
		expect(rome_converter.to_rome(51)).to eq "LI"	
	end

	it "Convert 123 to rome" do
		expect(rome_converter.to_rome(123)).to eq "CXXIII"	
	end

	it "Convert 488 to rome" do
		expect(rome_converter.to_rome(488)).to eq "CDLXXXVIII"	
	end

	it "Convert 2017 to rome" do
		expect(rome_converter.to_rome(2017)).to eq "MMXVII"	
	end

	it "Convert 3091 to rome" do
		expect(rome_converter.to_rome(3091)).to eq "MMMXCI"	
	end

	it "Convert 500 to rome" do
		expect(rome_converter.to_rome(500)).to eq "D"	
	end

	it "Convert 777 to rome" do
		expect(rome_converter.to_rome(500)).to eq "DCCLXXVII"	
	end

#--------------------------------------------------------------------------------------------

	it "Convert I to decimal" do
		expect(rome_converter.to_dec("I")).to eq(1)	
	end

	it "Convert XVI to decimal" do
		expect(rome_converter.to_dec("XVI")).to eq(16)	
	end

	it "Convert LII to decimal" do
		expect(rome_converter.to_dec("LII")).to eq(52)	
	end

	it "Convert DCCLXXVII to decimal" do
		expect(rome_converter.to_dec("DCCLXXVII")).to eq(777)	
	end

	it "Convert CDLIV to decimal" do
		expect(rome_converter.to_dec("CDLIV")).to eq(454)	
	end

	it "Convert DCCCLXXXVIII to decimal" do
		expect(rome_converter.to_dec("DCCCLXXXVIII")).to eq(888)	
	end

	it "Convert MMMDCLXXXIII to decimal" do
		expect(rome_converter.to_dec("MMMDCLXXXIII")).to eq(3683)	
	end

	it "Convert LXIII to decimal" do
		expect(rome_converter.to_dec("LXIII")).to eq(63)	
	end

	it "Convert CCCLXV to decimal" do
		expect(rome_converter.to_dec("CCCLXV")).to eq(365)	
	end
		
	it "Convert CCXLI to decimal" do
		expect(rome_converter.to_dec("CCXLI")).to eq(241)	
	end

	it "Convert XXXIV to decimal" do
		expect(rome_converter.to_dec("XXXIV")).to eq(34)	
	end

	it "Convert XCVIII to decimal" do
		expect(rome_converter.to_dec("XCVIII")).to eq(98)	
	end

	it "Convert C to decimal" do
		expect(rome_converter.to_dec("C")).to eq(100)	
	end

	it "Convert CD to decimal" do
		expect(rome_converter.to_dec("CD")).to eq(400)	
	end

	it "Convert CMXXIII to decimal" do
		expect(rome_converter.to_dec("CMXXIII")).to eq(923)	
	end
	
	it "Convert MLIV to decimal" do
		expect(rome_converter.to_dec("MLIV")).to eq(1054)	
	end

	it "Convert MCMLXIX to decimal" do
		expect(rome_converter.to_dec("MCMLXIX")).to eq(1969)	
	end

	it "Convert MMDCCCLVI to decimal" do
		expect(rome_converter.to_dec("MMDCCCLVI")).to eq(2856)	
	end

end




























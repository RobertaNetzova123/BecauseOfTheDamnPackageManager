class ApplicationController < ActionController::Base
	protect_from_forgery with: :null_sessions
	require 'csv'
	require 'linefit'

	def sums
		
		array = CSV.parse(params["file"].read, converters: :numeric)
		sum = 0
		for i in 0..array.length - 1
			sum += array[i][0]
		end
		render plain: "%.2f" % sum.ceil
	end


	def filters
		array = CSV.parse(params["file"].read, converters: :numeric)
		sum = 0
		for i in 0..array.length - 1
			if array[i][2] % 2 != 0
				sum = sum + array[i][1]
			end
		end
		render plain: "%.2f" % sum.ceil
		
	end
	
	def intervals 
        	file = params["file"].read
        	arr = CSV.parse(file, converters: :numeric)

        	maxsum = 0
        	for  i in 0..arr.length - 30
            	sum = 0
            		for  p in  0.. 29
               	        sum += arr[p+i][0]
              	end
            	if maxsum < sum 
               		 maxsum = sum
           	 end
        end
        render plain: "%.2f" % max_sum.ceil 
    end
	

	def lin
    	x = []
    	y = []

    	nope = params[:file]

    	CSV.foreach(nope.path) do |row|
      	x.push($INPUT_LINE_NUMBER)
      	y.push(row[0].to_f)
   	 end

    	lineFit = LineFit.new

    	lineFit.setData(x, y)

    	intercept, slope = lineFit.coefficients

    	render :html => '%.6f,%.6f' % [slope, intercept]
  end	
end



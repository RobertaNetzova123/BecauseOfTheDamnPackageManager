class MessagesController < ApplicationController
	def show
    		@message = Message.find(params[:id])
  	end

  	def new
    		@message = Message.new
  	end

  	def create
    		@message = Message.new(parameters)
   
    		@message.save
    		render :get
  	end
 
  	def get
    
  	end

private
  	def parameters
    		params.require(:message).permit(:text)
  	end
end

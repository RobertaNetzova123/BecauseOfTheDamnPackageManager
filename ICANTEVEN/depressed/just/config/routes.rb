Rails.application.routes.draw do
	
	root 'messages#new'
  
	resources :messages

	post "messages/api" => "messages#create"
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end

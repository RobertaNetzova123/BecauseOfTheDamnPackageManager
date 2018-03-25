Rails.application.routes.draw do
  resources :cinemas
  resources :films
	get '/B_18_Mihaela_Gadzhalovafilms/', to: 'cinemas#index'
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end

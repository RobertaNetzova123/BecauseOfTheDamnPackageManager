class ThreadingsController < ApplicationController
  before_action :set_threading, only: [:show, :edit, :update, :destroy]

  # GET /threadings
  # GET /threadings.json
  def index
    @threadings = Threading.all
  end

  # GET /threadings/1
  # GET /threadings/1.json
  def show
  end

  # GET /threadings/new
  def new
    @threading = Threading.new
  end

  # GET /threadings/1/edit
  def edit
  end

  # POST /threadings
  # POST /threadings.json
  def create
    @threading = Threading.new(threading_params)

    respond_to do |format|
      if @threading.save
        format.html { redirect_to @threading, notice: 'Threading was successfully created.' }
        format.json { render :show, status: :created, location: @threading }
      else
        format.html { render :new }
        format.json { render json: @threading.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /threadings/1
  # PATCH/PUT /threadings/1.json
  def update
    respond_to do |format|
      if @threading.update(threading_params)
        format.html { redirect_to @threading, notice: 'Threading was successfully updated.' }
        format.json { render :show, status: :ok, location: @threading }
      else
        format.html { render :edit }
        format.json { render json: @threading.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /threadings/1
  # DELETE /threadings/1.json
  def destroy
    @threading.destroy
    respond_to do |format|
      format.html { redirect_to threadings_url, notice: 'Threading was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_threading
      @threading = Threading.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def threading_params
      params.require(:threading).permit(:id, :value)
    end
end

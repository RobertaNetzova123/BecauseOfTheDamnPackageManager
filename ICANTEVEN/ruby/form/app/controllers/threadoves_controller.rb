class ThreadovesController < ApplicationController
  before_action :set_threadofe, only: [:show, :edit, :update, :destroy]

  # GET /threadoves
  # GET /threadoves.json
  def index
    @threadoves = Threadove.all
  end

  # GET /threadoves/1
  # GET /threadoves/1.json
  def show
  end

  # GET /threadoves/new
  def new
    @threadofe = Threadove.new
  end

  # GET /threadoves/1/edit
  def edit
  end

  # POST /threadoves
  # POST /threadoves.json
  def create
    @threadofe = Threadove.new(threadofe_params)

    respond_to do |format|
      if @threadofe.save
        format.html { redirect_to @threadofe, notice: 'Threadove was successfully created.' }
        format.json { render :show, status: :created, location: @threadofe }
      else
        format.html { render :new }
        format.json { render json: @threadofe.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /threadoves/1
  # PATCH/PUT /threadoves/1.json
  def update
    respond_to do |format|
      if @threadofe.update(threadofe_params)
        format.html { redirect_to @threadofe, notice: 'Threadove was successfully updated.' }
        format.json { render :show, status: :ok, location: @threadofe }
      else
        format.html { render :edit }
        format.json { render json: @threadofe.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /threadoves/1
  # DELETE /threadoves/1.json
  def destroy
    @threadofe.destroy
    respond_to do |format|
      format.html { redirect_to threadoves_url, notice: 'Threadove was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_threadofe
      @threadofe = Threadove.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def threadofe_params
      params.require(:threadofe).permit(:id, :value)
    end
end

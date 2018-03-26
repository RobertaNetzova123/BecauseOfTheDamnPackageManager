package org.elsys.gates;

public abstract class NandFactory {

	public static Gate makeNotGate(Wire in, Wire out, String name) {
		NandGate nandgate = new NandGate(in, in, out);
		CompositeGate gate = new CompositeGate(name);
		gate.addGate(nandgate);
		return gate;
	}

	public static Gate makeNotGate(Wire in, Wire out) {
		return makeNotGate(in, out, "NandNot");
	}

	public static Gate makeAndGate(Wire in1, Wire in2, Wire out, String name) {
		Wire in3 = new Wire(name);
		NandGate nandgate1 = new NandGate(in1, in2, in3);
		NandGate nandgate2 = new NandGate(in3, in3, out);
		CompositeGate gate = new CompositeGate(name);
		gate.addGate(nandgate1);
		gate.addGate(nandgate2);
		return gate;
	}

	public static Gate makeAndGate(Wire in1, Wire in2, Wire out) {
		return makeAndGate(in1, in2, out, "NandAnd");
	}

	public static Gate makeOrGate(Wire in1, Wire in2, Wire out, String name) {
		return null;
	}

	public static Gate makeOrGate(Wire in1, Wire in2, Wire out) {
		return makeOrGate(in1, in2, out, "NandOr");
	}

	public static Gate makeXorGate(Wire in1, Wire in2, Wire out, String name) {
		return null;
	}

	public static Gate makeXorGate(Wire in1, Wire in2, Wire out) {
		return makeXorGate(in1, in2, out, "NandXor");
	}
	

}

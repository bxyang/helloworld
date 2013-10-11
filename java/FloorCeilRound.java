


public class FloorCeilRound {
	public static void main(String[] args) throws Exception {
		double pos_num = 3.12;
		System.out.printf("floor(%f) = %f\n", pos_num, Math.floor(pos_num));
		System.out.printf("floor(%f) = %f\n", -pos_num, Math.floor(-pos_num));
		System.out.printf("ceil(%f) = %f\n", pos_num, Math.ceil(pos_num));
		System.out.printf("ceil(%f) = %f\n", -pos_num, Math.ceil(-pos_num));
		System.out.printf("round(%f) = %d\n", pos_num, Math.round(pos_num));
		System.out.printf("round(%f) = %d\n", -pos_num, Math.round(-pos_num));
		System.out.printf("round(%f) = %d\n", pos_num+0.5, Math.round(pos_num+0.5));
		System.out.printf("round(%f) = %d\n", -pos_num-0.5, Math.round(-pos_num-0.5));
	}
}

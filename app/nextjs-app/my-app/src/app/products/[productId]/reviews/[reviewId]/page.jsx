import {notFound} from "next/navigation"
export default function ReviewDetail({params}){
    const productId = parseInt(params.productId);
    const reviewId = parseInt(params.reviewId);
    if(productId > 100 || reviewId > 100){
        throw new Error("Custom thrown error");
    }
    return(
        <h1>
            Review {params.reviewId} for product {params.productId}
        </h1>
    );
}
